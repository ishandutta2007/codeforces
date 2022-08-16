n, m = map(int, input().split())
MOD = 1000000007
ans = pow(pow(2, m, MOD)-1+MOD, n, MOD)
print(ans)