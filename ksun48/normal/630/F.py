n = int(input())

a = n*(n-1)*(n-2)*(n-3)*(n-4)//120
b = a*(n-5)//6
c = b*(n-6)//7
print(a+b+c)