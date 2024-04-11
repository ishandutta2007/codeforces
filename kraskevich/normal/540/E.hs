-- This solution is purely functional. 

{-#LANGUAGE BangPatterns #-}

import Control.Monad
import Data.Int
import Data.List
import qualified Data.IntMap.Strict as M 
import Data.Tuple
import Data.Maybe(fromJust)
import qualified Data.IntSet as S
import qualified Data.ByteString.Char8 as B
import Control.DeepSeq

data Node = Node !Int !Node !Node | Empty

getSum :: Node -> Int
getSum (Node s _ _) = s

build :: Int -> Int -> Node
build !l !r 
    | l == r = Node 0 Empty Empty
    | otherwise =  
        let m = (l + r) `div` 2 
        in Node 0 (build l m) (build (m + 1) r)

update :: Node -> Int -> Int -> Int -> Int -> Node
update !(Node !val !left !right) !l !r !pos !delta  
    | l == r = Node (val + delta) Empty Empty
    | otherwise = 
        let m = (l + r) `div` 2
        in
            if pos <= m then 
                Node (val + delta) (update left l m pos delta) right
            else
                Node (val + delta) left (update right (m + 1) r pos delta)
   

get :: Node -> Int -> Int -> Int -> Int -> Int
get !(Node !val !left !right) !tl !tr !l !r 
    | l == tl && r == tr = val
    | otherwise = 
        let m = (tl + tr) `div` 2
        in 
            if l <= m then
                (get left tl m l (min r m)) + getSum right
            else
                get right (m + 1) tr (max (m + 1) l) r
solve :: [(Int, Int)] -> Int64 

solve xs = 
    let n = length xs
        step :: (Node, Int64) -> (Int, Int) -> (Node, Int64)
        step (!root, !res) (!pos, !size) =
            let add = ((fromIntegral size) :: Int64) * 
                      (fromIntegral $ get root 0 (n - 1) pos (n - 1))
                root' = update root 0 (n - 1) pos size   
            in
                (root', res + add)                            
    in        
        snd $ foldl' step (build 0 (n - 1), 0::Int64) xs    
    
makeSwaps :: [(Int, Int)] -> ([Int], [Int]) -> [(Int, Int)]
makeSwaps swaps !(vals, s) =
    let
        initVals = M.fromAscList $ zip vals vals
        step !vs (!a, !b) = 
            let va = vs M.! a
                vb = vs M.! b
                vs' = M.insert a vb vs
            in
                M.insert b va vs'
        finalVals = M.assocs $ foldl' step initVals swaps
        compressed = finalVals `deepseq` M.fromAscList $ zip vals (zip [0..] s)
   in
        map (\(_, a) -> (let (f, s) = compressed M.! a in (f, s))) finalVals
        
getSizes :: [Int] -> ([Int], [Int])
getSizes [] = ([], [])
getSizes [x] = ([x], [1])
getSizes (x:y:xs) 
    | x == y - 1 = 
        let (!a, !b) = getSizes(y:xs)
        in (x:a, 1:b) 
    | otherwise = 
        let (!a, !b) = getSizes(y:xs)
        in (x:x + 1:a, 1:y - x - 1:b)

main = do
    input <- B.getContents
    let (line:lines) = B.lines input
    let n = lines `deepseq` (fst . fromJust $ B.readInt line)
    let swaps = map (\l -> let [x, y] = B.words l in (fst . fromJust $ B.readInt x, fst . fromJust $ B.readInt y)) lines 
    let sizes = swaps `deepseq` getSizes (S.elems $ foldl' (\acc (a, b) -> S.insert a (S.insert b acc)) S.empty swaps)               
    let afterSwaps = sizes `deepseq` makeSwaps swaps sizes
    let size = afterSwaps `deepseq` length (fst sizes)
    let res = solve afterSwaps 
    print res