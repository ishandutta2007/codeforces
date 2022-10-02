sym="AHIMOoTUVvWwXxY"
rev={'b':'d','d':'b','p':'q','q':'p'}
S=input()
N=len(S)
ok=True
for i in range(N // 2):
    o=S[N-i-1]
    ok &= (S[i] in sym and S[i] == o) or (S[i] in rev and rev[S[i]] == o)
if N & 1:
    ok &= S[N//2] in sym
print('TAK' if ok else 'NIE')