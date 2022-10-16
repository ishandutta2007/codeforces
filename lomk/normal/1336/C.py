'''input
cbaabccadacadbaacbadddcdabcacdbbabccbbcbbcbbaadcabadcbdcadddccbbbbdacdbcbaddacaadbcddadbabbdbbacabdd
cccdacdabbacbbcacdca
'''
from typing import List
import sys
dp = [[0 for i in range(3005)] for i in range(3005)]
a = input()
pref = input()
mod = 998244353

for lx in range(1, len(a) + 1):
    for l in range(0, len(a)):
        r = l + lx - 1
        if r >= len(a):
            break
        cur = a[r - l]
        if l == r:
            dp[l][r] = 2 if ((l < len(pref) and cur == pref[l]) or l >= len(pref)) else 0
            continue
        if l >= len(pref) or (l < len(pref) and cur == pref[l]):
            dp[l][r] += dp[l + 1][r]
        if r >= len(pref) or (r < len(pref) and cur == pref[r]):
            dp[l][r] += dp[l][r - 1]
        dp[l][r] %= mod

ans = 0
for i in range(len(pref) - 1, len(a)):
    ans += dp[0][i]
ans %= mod
print(ans)