q=int(input())
for _ in range(q):
    s=input()
    if s=="":
        print(0)
        print()
        continue
    aa=min(s.count("U"),s.count("D"))
    bb=min(s.count("L"),s.count("R"))
    if bb==0 and aa==0:
        print(0)
        print()
        continue
    elif aa==0:
        print(2)
        print("RL")
        continue
    elif bb==0:
        print(2)
        print("DU")
        continue
    print(aa*2+bb*2)
    print("D"*aa+"R"*bb+"U"*aa+"L"*bb)