import Data.List
import qualified Data.Map
import Data.Maybe
import Control.Monad
import Control.Applicative
import Data.Int
import qualified Data.ByteString.Char8 as B

getGestures :: Int -> Int -> Int
getGestures pos perScreen = pos `div` perScreen + 1

getIntList :: IO [Int]
getIntList = parseLine <$> B.getLine
    where
        parseLine = (map (fst . fromJust . B.readInt)) . B.words
        
type IntMap = Data.Map.Map Int Int

getMaps :: [Int] -> (IntMap, IntMap)
getMaps array = foldl' (\ (p2v, v2p) (v, p) -> 
                        (Data.Map.insert p v p2v, Data.Map.insert v p v2p))
                 (Data.Map.empty, Data.Map.empty) (zip array [0..])

solve :: [Int] -> IntMap -> IntMap -> Int64 -> Int -> Int64
solve [] _ _ acc _ = acc
solve (x:xs) posToVal valToPos acc perScreen = 
    let acc' = acc + fromIntegral (getGestures (valToPos Data.Map.! x) perScreen)
        (posToVal', valToPos') = moveForward posToVal valToPos x
    in solve xs posToVal' valToPos' acc' perScreen
    where 
        moveForward p2v v2p v =
            let curPos = v2p Data.Map.! v
                prevPos = curPos - 1
                curVal = v
                prevVal = fromMaybe (-1) (Data.Map.lookup prevPos p2v)
            in 
                if prevPos == -1 then
                    (p2v, v2p)
                else
                    let p2v' = Data.Map.insert curPos prevVal p2v
                        p2v'' = Data.Map.insert prevPos curVal p2v'
                        v2p' = Data.Map.insert curVal prevPos v2p
                        v2p'' = Data.Map.insert prevVal curPos v2p'
                    in (p2v'', v2p'')

main = do
    [n, m, k] <- getIntList    
    a <- getIntList
    b <- getIntList
    let (posToVal, valToPos) = getMaps $ map (\x -> x - 1) a
    let res = solve (map (\x -> x - 1) b) posToVal valToPos 0 k
    print res