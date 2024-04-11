import sys
input=sys.stdin.readline
n=int(input())
it=set()
for _ in range(n):
    a,b,c=map(int,input().split())
    it.add((a,b,c,_))
for i in range(n//2):
    aa=it.pop()
    b=it.pop()
    mi=b[:]
    it.add(b)
    for j in it:
        st=True
        for k in range(3):
            if min(aa[k],mi[k])<=j[k]<=max(aa[k],mi[k]):
                pass
            else:
                st=False
        if st:
            mi=j[:]
    it.remove(mi)
    print(aa[3]+1,mi[3]+1)