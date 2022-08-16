n=int(input())
it=list(map(int,input().split()))
mod=[i%2 for i in it]
if set(mod)==set([0,1]):
    it.sort()
for i in it:
    print(i,end=" ")
print()