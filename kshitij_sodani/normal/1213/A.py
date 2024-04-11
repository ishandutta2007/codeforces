# cook your dish here
n=int(input())
it=list(map(int,input().split()))
a=len([i for i in it if i%2==0])
b=n-a
if a>=b:
    print(b)
else:
    print(a)