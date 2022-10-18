r = lambda: map(int, input().split())

def main():
	n, t = r()
	a = list(r())
	for i, x in enumerate(a):
		t -= 86400 - x
		if t <= 0:
			print(i + 1)
			return
main()