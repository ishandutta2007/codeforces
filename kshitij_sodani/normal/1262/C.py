t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    s=input()
  # print(n**3)
    arr=""
    for i in range(k):
        arr+="()"
    s=list(s)
    tot=0
    co=[]

    for i in range(k-1):
        if s[2*i]!="(":
            x=s[2*i:].index("(")
            ind=x+i*2
            ind+=1
        
            co.append([2*i+1,ind])
            s[i*2],s[ind-1]=s[ind-1],s[i*2]

            if ind-(2*i+1)>1:
                co.append([2*i+2,ind-1])
             #   s[i*2+1],s[ind-2]=s[ind-2],s[i*2+1]

                tot+=1
            tot+=1
            
        if s[2*i+1]!=")":
            x=s[2*i+1:].index(")")
            ind=x+i*2+1
          #  print(ind,x,1)
            ind+=1
          #  print(ind,x,1)
            co.append([i*2+2,ind])
            s[i*2+1],s[ind-1]=s[ind-1],s[i*2+1]
            tot+=1
            if ind-(2*i+2)>1:
                co.append([i*2+2+1,ind-1])
              #  s[i*2+2],s[ind-2]=s[ind-2],s[i*2+2]

                tot+=1
   # print(''.join(s))
 #   print(co)
    for i in range(2*k-2,2*k-2+(n-2*k+2)//2):
        if s[i]!="(":
            
            x=s[i:].index("(")
            ind=x+i
            ind+=1
           # print(i,ind)
            co.append([i+1,ind])
            s[i],s[ind-1]=s[ind-1],s[i]

            #if ind-(i+1)>1:
             #   co.append([i+2,ind-1])
             #   s[i*2+1],s[ind-2]=s[ind-2],s[i*2+1]
            
              #  tot+=1
            tot+=1
    

            
     #   print(''.join(s))
   
  #  
   # print(''.join(s))
    co=[i for i in co if i[0]!=i[1]]
    print(len(co))
    for i in co:
        print(*i)