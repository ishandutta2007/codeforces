n=int(input())
it=list(map(int,input().split()))
if len(set(it))>1:
    it.sort()
    for i in it:
        print(i,end=" ")
    print()
else:
    print(-1)