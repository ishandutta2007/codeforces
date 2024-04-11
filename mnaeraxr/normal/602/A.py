def read():
	n, b = map(int, input().split())
	t = 0
	l = list(map(int, input().split()))
	for i in l:
		t = t * b + i
	return t

a = read()
b = read()
if a == b:
	print("=")
elif a < b:
	print("<")
else:
	print(">")