k,p=map(int,input().split())
print(sum(int(str(i)+str(i)[::-1]) for i in range(1,k+1))%p)