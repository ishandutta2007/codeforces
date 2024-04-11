import Data.List 
import Data.Char

toLowerCase :: String -> String
toLowerCase = map toLower 

hasAllLetters :: String -> Bool
hasAllLetters s = Data.List.length (nub s) == 26  

main = do
   getLine
   line <- getLine
   putStrLn $ if hasAllLetters $ toLowerCase line then "YES" else "NO"