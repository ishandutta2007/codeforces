n=input()
h=[input() for i in range(n)]
print sum(abs(h[i]-h[i+1])+1 for i in range(n-1))+h[0]+n;