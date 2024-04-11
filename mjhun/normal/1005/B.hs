import Data.List

toint s = (read s) :: Integer

doit [] = 0
doit ((x,y):xs) =
	if x == y then
		1 + doit xs
	else
		0

solve::String -> String
solve ss =
	let [s,t] = map reverse (words ss) in
	show (length s + length t - 2 * doit (zip s t)) ++ "\n"

main = do
  interact $ solve