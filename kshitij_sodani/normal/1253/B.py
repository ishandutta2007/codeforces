n=int(input())
it=list(map(int,input().split()))
ss=set()
tt=set()
ans=[0]
for i in it:
    if i>0 and i in tt:
        ans.append(1)
        if ss!=set():
            ans=-1
            break
        ss=set([i])
        tt=set([i])
        continue
    if i>0 and i not in tt:
        ans[-1]+=1
        ss.add(i)
        tt.add(i)
    elif i<0 and abs(i) not in ss:
        ans=-1
        break
    elif i<0 and abs(i) in ss:
        ss.remove(-i)
        ans[-1]+=1
        if ss==set():
            ans.append(0)
            tt=set()
   # print(ans,ss)
if ss!=set():
    ans=-1
if ans==-1:
    print(ans)
else:
    print(len([i for i in ans if i!=0]))
    for i in range(len([i for i in ans if i!=0])):
        print(ans[i],end=" ")