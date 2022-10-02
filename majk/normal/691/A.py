N=int(input())
S=input()
res = False
if N == 1 and S.count('1') == 1:
    res = True
elif N > 1 and S.count('1') == N-1:
    res = True
print('YES' if res else 'NO')