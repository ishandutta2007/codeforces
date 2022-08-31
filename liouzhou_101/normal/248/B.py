n=input()
print -1 if n<3 else 210 if n==3 else "1"+"0"*(n-4)+"%03d"%(210-pow(10,n-1,210))