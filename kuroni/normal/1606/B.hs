{-# LANGUAGE BangPatterns #-}

import Control.Monad
import qualified Data.ByteString.Char8 as C
import Data.List
import Data.Maybe

main :: IO ()
main = do
  [t] <- readInts
  replicateM_ t $ do
    [n, k] <- readIntegers
    print $ solve n k 1

readInts :: IO [Int]
readInts = map (fst . fromJust . C.readInt) . C.words <$> C.getLine

readIntegers :: IO [Integer]
readIntegers = map (fst . fromJust . C.readInteger) . C.words <$> C.getLine

solve n k a
  | a >= n = 0
  | a >= k = (n - a - 1) `div` k + 1
  | otherwise = 1 + (solve n k $ 2 * a)