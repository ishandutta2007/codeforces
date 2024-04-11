def bin(a):
    x=""
    while a:
        x+=str(a%3)
        a//=3
    return x[-1::-1]

x=10**18
pre=[1]
while pre[-1]<=x:
    pre.append(pre[-1]*3)
q=int(input())
for _ in range(q):
    n=int(input())
    aa=list(bin(n))
    aa=[int(i) for i in aa]
    #print(aa)
    x=len(aa)
    z=-1
    ans=aa[:]
    for i in range(len(aa)):
        if aa[i]==0:
            z=max(z,i)
        if aa[i]==2:
            if z==-1:
                ans=[1]+[0 for i in range(x)]
            else:
                ans=ans[:z]+[1]+[0 for i in range(z+1,x)]
            break
            
            
  #  print(z)
    tot=0
    for i in range(len(ans)):
        if ans[-i-1]==1:
            tot+=pre[i]
    print(tot)