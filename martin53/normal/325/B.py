import math
n=input()
pos=0
arr = []        #create the array
for i in range(100): # initializes to 0
    arr.append(n+1)

for p in range(0,64):
    #print(p)
    a=1
    b=2**(p+1)
    b=b-3
    c=n*(-2)
    D=b*b-4*a*c
    #print(D)
    if(D>=0):
        ok=0
        not_ok=D
        not_ok=not_ok+1
        while(not_ok-ok>1):
            av=(ok+not_ok)
            if(av%2==1):
                av=(av-1)/2
            else:
                av=av/2
            if(av*av<=D):
                ok=av
            else:
                not_ok=av
        k=ok
        #print(k)
        #print(k*k)
        if(k*k==D):
            q1=(-b+k)/(2*a)
            q2=(-b-k)/(2*a)
            #print(q1)
            #print(q2)
            if(q1%2==1 and q1>0):
                arr[pos]=q1*(2**p)
                pos=pos+1
            if(q2%2==1 and q2>0):
                arr[pos]=q2*(2**p)
                pos=pos+1
    #print("---")
if(pos==0):
    print(-1)
else:
    #print(arr[0])
    arr.sort();
    for p in range(0,pos):
        print(arr[p])