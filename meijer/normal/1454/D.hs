import Data.List

factors :: Integer -> [Integer]
factors 1 = []
factors n = if b == [] then [n] else (head b) : factors (n`div`(head b))
  where a = takeWhile (\x -> x*x <= n) [2..n]
        b = filter (\x -> n`mod`x==0) a

solve :: Integer -> String
solve n = (show lenAns) ++ "\n" ++ (unwords $ map show $ ans)
  where fact = reverse $ sort $ map (\a -> (length a, head a)) $ group $ factors n
        lenAns = fst $ head fact
        f cur sm (x:xs)
          | cur == fst x = f cur (sm*(snd x)) xs
          | otherwise = sm : (f (cur-1) sm (x:xs))
        f cur sm [] = sm : (f (cur-1) sm [])
        ans = take lenAns $ f lenAns 1 fact

main = interact $ unlines . map (solve . read) . tail . lines