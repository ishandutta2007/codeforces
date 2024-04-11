from sys import stdin, stdout  

n=input()

x0,y0=0,0
sx,sy,s2=0,0,0

qx=[0]*n
qy=[0]*n

for i in xrange(n):
	px,py=map(int,raw_input().split())
	qx[i],qy[i]=px,py
	sx+=px
	sy+=py
	s2+=qx[i]*qx[i]+qy[i]*qy[i]


for i in xrange(n):
	if (n*qx[i],n*qy[i])!=(sx,sy):
		p,q=qx[i],qy[i]
		break

m=input()
a=2*p*n-2*sx
b=2*q*n-2*sy
pc=n*(p*p+q*q)-s2
pdt=-(a*a*p*p+2*a*b*p*q+b*b*q*q)
sr=a*a+b*b

def isqrt(x):
    nn = int(x)
    if nn == 0:
        return 0
    fa, fb = divmod(nn.bit_length(), 2)
    x = 2**(fa+fb)
    while True:
        y = (x + nn/x)/2
        if y >= x:
            return x
        x = y
pans=[]

def gethash(x):
	return x*13331+23333

for i in xrange(m):
	d=map(int,raw_input().split())
	sd=sum(d)
	hd=0
	for j in xrange(n):
		hd^=gethash(d[j])
	ans=[]
	for j in xrange(n):
		if j>=1 and d[j]==d[j-1]: continue
		c=pc+sd-n*d[j]
		dt=pdt+a*a*d[j]+2*a*c*p+b*b*d[j]+2*b*c*q-c*c
		if dt<0: continue
		idt=isqrt(dt)
		if idt*idt!=dt:
			continue
		def check(idt):
			x=(b*idt-a*b*q+a*c+b*b*p)
			y=(-a*idt+a*a*q+b*c-a*b*p)
			if x%sr!=0:
				return
			x,y=x/sr,y/sr
			z=0
			for k in xrange(n):
				z^=gethash((x-qx[k])**2+(y-qy[k])**2)
			if z==hd:
				ans.append([x,y])
		check(idt)
		if idt!=0: check(-idt)
	ans.sort()
	buf=[]
	buf.append(len(ans))
	for x in ans:
		buf.append(x[0])
		buf.append(x[1])
	pans.append(" ".join(map(str,buf)))
stdout.write("\n".join(pans))