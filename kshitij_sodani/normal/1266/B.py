n=int(input())

        
it=list(map(int,input().split()))
for x in it:
    if x%14>=1 and x%14<=6 and x>=15:
        print("YES")
    else:
        print("NO")