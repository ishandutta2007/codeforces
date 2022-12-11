n, m = map(int, input().split())

if (max(n, m) == 6):
	print("1/6")
if (max(n, m) == 5):
	print("1/3")
if (max(n, m) == 4):
	print("1/2")
if (max(n, m) == 3):
	print("2/3")
if (max(n, m) == 2):
	print("5/6")
if (max(n, m) == 1):
	print("1/1")