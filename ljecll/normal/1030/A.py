n = input()
arr = map(int, input().split())

hard = 0

for x in arr:
	if x == 1:
		hard = 1

if hard == 1:
	print("HARD")
else:
	print("EASY")