T=input()
for i in xrange(T):
  x,y,a,b=map(int,raw_input().split())
  if (y-x)%(a+b)!=0:
    print -1
  else:
    print (y-x)/(a+b)