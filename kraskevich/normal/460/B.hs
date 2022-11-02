sumOfDigits :: Integer -> Integer
sumOfDigits n 
    | n > 0 = n `mod` 10 + sumOfDigits (n `div` 10)
    | otherwise =   0

root :: Integer -> Integer -> Integer -> Integer -> Integer
root a b c s = let x = b * s ^ a + c
               in if s == sumOfDigits x 
                      then x
                      else -1

getRoots :: Integer -> Integer -> Integer -> [Integer]
getRoots a b c = foldr (\s acc -> if root a b c s /= -1 then root a b c s : acc else acc) 
                 [] [1..100] 

main = do
    line <- getLine
    let xs = map read (words line) :: [Integer]
    let res = takeWhile (< 10 ^ 9) (getRoots (xs !! 0) (xs !! 1) (xs !! 2))
    putStrLn $ show (length res)
    putStrLn $ foldl (\acc x -> acc ++ " " ++ show x) "" res