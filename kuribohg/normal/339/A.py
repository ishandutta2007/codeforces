a=list(input().split('+'));
a.sort();
for i in range(len(a)):
    print(a[i],end="");
    if i!=len(a)-1:
        print('+',end="");