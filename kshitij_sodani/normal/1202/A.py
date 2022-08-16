t=int(input())
for _ in range(t):
    x=input()
    y=input()
    l=0
    for i in y[-1::-1]:
        if i=="1":
            break
        l+=1
    j=0
    for i in range(len(x)):
        if j<l:
            pass
        else:
            if x[-i-1]=="1":
                ind=i
                break
            
                
        j+=1
    print(ind-l)