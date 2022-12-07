m, n = map(int,input().split())
if m % 2 == 0 or n % 2 == 0:
    ans = m * n/2
else :
    ans = (m * n - 1)/2
print(int(ans))