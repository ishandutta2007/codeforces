from sys import stdout
aa=[]
a=2**7-1
for i in range(100):
    aa.append(i+1)
stdout.flush()
print("?",*aa)
stdout.flush()
x=bin(int(input()))[2:]
x="0"*(14-len(x))+x
#print(x)
num=0
for i in range(13,6,-1):
    if x[-i-1]=="1":
       # print(i)
        num+=2**i
#print(x)
#print(num)
aa=[]
a=0
for i in range(13,6,-1):
    a+=2**i
#print(bin(a))
aa=[]
a=2**7
for i in range(100):
    aa.append(a*(i+1))
stdout.flush()
print("?",*aa)
stdout.flush()
x=bin(int(input()))[2:]
x="0"*(14-len(x))+x
#print(x)
for i in range(7):
    if x[-i-1]=="1":
        num+=2**i
stdout.flush()
print("!",num)