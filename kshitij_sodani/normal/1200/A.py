n=int(input())
s=input()
r=[0]*10
for i in s:
    if i=="L":
        for i in range(10):
            if r[i]==0:
                mid=i
                break

        r[mid]=1
    elif i=="R":
        for i in range(9,-1,-1):
            if r[i]==0:
                mid=i
                break
        r[mid]=1
    else:
        r[int(i)]=0
  #  print(r)
for i in r:
    print(i,end="")