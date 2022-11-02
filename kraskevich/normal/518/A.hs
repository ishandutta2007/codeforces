import Data.List

getNextString :: String -> Int -> String
getNextString s pos = take pos s ++ [next (s !! pos)] 
        ++ replicate (length s - pos - 1) 'a'
    where 
        next :: Char -> Char
        next 'z' = 'z'
        next c = succ c

solve :: String -> String -> [String]
solve s t = 
    filter (\ x -> s < x && x < t) (map (getNextString s) [0..length s - 1])  
     
main = do
    s <- getLine
    t <- getLine
    let res = solve s t
    if null res then
        putStrLn "No such string"
    else
        putStrLn $ head res