n=input()
p=sum(int(raw_input().split()[0])for i in range(n))
p=p//1000+(p%1000>500)
print 'G'*p+'A'*(n-p)