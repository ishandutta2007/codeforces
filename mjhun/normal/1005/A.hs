import Data.List

toint s = (read s) :: Integer

doit [] i = [i]
doit (x:xs) i =
	if x == 1 && i > 0 then
		i:(doit xs 1)
	else
		doit xs (i+1)

solve::String -> String
solve ss =
	let s = map toint (tail (words ss)) in
	let r = doit s 0 in
	(show (length r)) ++ "\n" ++ intercalate " " (map show r) ++ "\n"

main = do
  interact $ solve