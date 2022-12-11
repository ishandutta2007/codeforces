TC = int(input())

for t in range(0, TC):
	B, P, F = map(int, input().split())
	if (B % 2 == 1):
		B = B - 1
	H, C = map(int, input().split())
	ans = 0
	if (H > C):
		H, C = C, H
		P, F = F, P
	take = min(B // 2, F)
	B = B - 2 * take
	F = F - take
	ans = ans + take * C
	take = min(B // 2, P)
	B = B - 2 * take
	P = P - take
	ans = ans + take * H
	print(ans)