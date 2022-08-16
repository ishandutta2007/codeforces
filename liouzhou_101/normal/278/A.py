R=lambda:map(int,raw_input().split())
n=input()
d=[0]+R()
x,y=R()
if x>y:x,y=y,x
p=sum(d[i]for i in range(x,y))
print min(p,sum(d)-p)