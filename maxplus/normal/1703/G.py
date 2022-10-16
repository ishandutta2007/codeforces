I=lambda:map(int,input().split());t,=I()
while t:
 t-=1;_,k=I();l=[0]*31
 for a in I():l=[max([l[i]-k*(i<30),l[i-1]][:i+1])+(a>>i)for i in range(31)]
 print(max(l))