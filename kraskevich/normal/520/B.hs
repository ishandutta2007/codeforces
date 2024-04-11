import Data.List
import qualified Data.Set as Set
import qualified Data.Map as Map 

maxNumber :: Int
maxNumber = 20 * 1000 + 1

infinity :: Int
infinity = 1000 * 1000 * 1000

type IntMap = Map.Map Int Int
type Queue = Set.Set (Int, Int)

getInitDist :: Int -> IntMap
getInitDist start = 
    Map.fromList (zip [0..start - 1] (repeat infinity) ++ [(start, 0)] 
        ++ zip [start + 1..maxNumber - 1] (repeat infinity))
    
getInitQueue :: Int -> Queue
getInitQueue start = Set.singleton (0, start)

bfs :: Queue -> IntMap -> IntMap
bfs queue dist 
    | Set.null queue = dist
    | otherwise = 
        let (_, v) = Set.findMin queue
            queue' = Set.deleteMin queue
            (queue'', dist') = putVertex queue' dist (2 * v) v
            (queue''', dist'') = putVertex queue'' dist' (v - 1) v  
        in 
            bfs queue''' dist''
        where
            putVertex :: Queue -> IntMap -> Int -> Int -> (Queue, IntMap)
            putVertex q d u v
                | u < 0 || u >= maxNumber = (q, d)
                | d Map.! u /= infinity = (q, d)
                | otherwise =
                    let newDist = (d Map.! v) + 1
                        d' = Map.insert u newDist d
                        q' = Set.insert (newDist, u) q
                     in (q', d') 

main = do
   line <- getLine
   let [n, m] = (map read (words line)) :: [Int]
   let dist = getInitDist n
   let queue = getInitQueue n
   let res = bfs queue dist
   putStrLn $ show (res Map.! m)