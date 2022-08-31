n=input()
a=map(int,raw_input().split())
print max(sum(a[k] for k in range(i)+range(j+1,n))+sum(1-a[k] for k in range(i,j+1)) for i in range(n) for j in range(i,n))