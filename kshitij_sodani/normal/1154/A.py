a,b,c,ab=map(int,input().split())
ll=[a,b,c,ab]
ll.sort()
for i in range(3):
    print(ll[-1]-ll[i],end=" ")