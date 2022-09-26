s = str(input())
n = len(s)
ns = ['0' for i in range(n)]
st = []
for i in range (n):
    if (s[i] == '0'):
        if (len(st)):
            ns[st.pop()] = '1'
    else:
        st.append(i)
print(''.join(ns))