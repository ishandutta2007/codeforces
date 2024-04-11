arr = list(map(int, input().split()))
s = input()
#print(s)

ans = 0
for c in s:
	ans += arr[ord(c) - ord('1')]

print(ans)