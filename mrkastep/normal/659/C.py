a = input().split()
n = int(a[0])
m = int(a[1])
d={}
for i in input().split():
    d[int(i)]=1

ans = []

cnt = 1
while m>0:
    if m-cnt<0:
        break
    if(d.get(cnt)==None):
        ans.append(cnt)
        m-=cnt
    cnt+=1

print(len(ans))
for i in ans:
    print(i,' ',sep='',end='')