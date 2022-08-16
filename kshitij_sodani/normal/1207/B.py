a,b=map(int,input().split())
aa=[[0]*(b+2)]
for i in range(a):
    it=list(map(int,input().split()))
    aa.append([0]+it+[0])
aa.append([0]*(b+2))
st=False
ans=[]
ss=[[0]*b for i in range(a)]
for i in range(1,a+1):
    for j in range(1,b+1):
     #   print(i,j,"i")
        if aa[i][j]==1 and aa[i][j+1]==1 and aa[i+1][j]==1 and aa[i+1][j+1]==1:

          #  print(i,j)
            
           # print(i,j)
            ss[i-1][j-1]=1
            ss[i-1][j]=1
            ss[i][j]=1
            ss[i][j-1]=1
            ans.append((i,j))

        elif aa[i][j]==1:
            if ss[i-1][j-1]==0:
             #   print(i,j)
                st=True
                break
    if st:
        break
##        if aa[i][j]==1:
##            ar=[[aa[i-1][j],aa[i][j-1],aa[i-1][j-1]],
##                 [aa[i-1][j],aa[i-1][j+1],aa[i][j+1]],
##                 [aa[i][j+1],aa[i+1][j+1],aa[i+1][j]],
##                 [aa[i+1][j],aa[i+1][j-1],aa[i+1][j]]]
##            ar2=[[[i-1,j],[i,j-1],[i-1,j-1]],
##                 [[i-1,j],[i-1,j+1],[i,j+1]],
##                 [[i,j+1],[i+1,j+1],[i+1,j]],
##                 [[i+1,j],[i+1,j-1],[i+1,j]]]
##            if [1,1,1] not in ar:
##                 st=True
##                 break
##           
##          #  print(i,j)
##            ii=ar.index([1,1,1])
##            o=ar2[ii]+[[i,j]]
##           # print(o)
##            o.sort()
##        #    o=o[0]
##          #  print(o,a,b)
##            if o[0][0]>=a or o[0][1]>=b:
##                continue
##            ans.append((o[0][0],o[0][1]))
##    if st:
##        break
if st:
    print(-1)
else:
    ans=set(ans)
    ans=list(ans)
    print(len(ans))
    for i in ans:
        print(*i)