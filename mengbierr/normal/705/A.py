n=int(input())
for i in range(n-1):
    if i%2==1:
        print("I love that ",end='')
    else:
        print("I hate that ",end='')
if n%2==0:
    print("I love it")
else:
    print("I hate it")