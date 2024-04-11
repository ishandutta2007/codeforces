import Data.List 

modulo :: Integer
modulo = 1000 * 1000 * 1000 + 7

powerMod :: Integer -> Integer -> Integer -> Integer
powerMod base 0 _ = 1
powerMod base exp modulo
    | exp `mod` 2 == 1 = base * powerMod base (exp - 1) modulo `mod` modulo
    | otherwise = 
        let halfPow = powerMod base (exp `div` 2) modulo
        in 
            halfPow * halfPow `mod` modulo  
            
count :: Char -> String -> Int
count c str = length $ filter (== c) str

main = do
    getLine
    s <- getLine
    let frequences = [count 'A' s, count 'C' s, count 'T' s, count 'G' s]
    let max = maximum frequences 
    let cntMax = length $ filter(== max) frequences
    putStrLn $ show $ 
        powerMod (fromIntegral cntMax) (fromIntegral (length s)) modulo