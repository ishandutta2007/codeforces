{-# LANGUAGE BangPatterns #-}

import Control.Monad (replicateM_)
import qualified Data.ByteString.Char8 as C (getLine, readInt, words)
import Data.List (foldl', sort)
import Data.Maybe (fromJust)

main :: IO ()
main = do
  [t] <- readInts
  replicateM_ t $ do
      s <- getLine
      putStrLn $ solve s

readInts :: IO [Int]
readInts = map (fst . fromJust . C.readInt) . C.words <$> C.getLine

solve :: [a] -> [a]
solve (a:as)
    | null as = [a]
    | otherwise = last as:as