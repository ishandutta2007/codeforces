from decimal import Decimal
import math

x,y,z = map(Decimal, input().split())

arr = []
for i in range(10):
    arr.append(0)
output=["x^y^z","x^z^y","(x^y)^z","y^x^z","y^z^x","(y^x)^z","z^x^y","z^y^x","(z^x)^y"]

arr[0]=x.ln()*y**z
arr[1]=x.ln()*z**y
arr[2]=x.ln()*y*z
arr[3]=y.ln()*x**z
arr[4]=y.ln()*z**x
arr[5]=y.ln()*x*z
arr[6]=z.ln()*x**y
arr[7]=z.ln()*y**x
arr[8]=z.ln()*x*y

maxi=0
for i in range(1,9):
    d=arr[i]-arr[maxi]
    if(d>1/1000000000):
        maxi=i
print(output[maxi])