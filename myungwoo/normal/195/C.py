import re,sys
N = input()
stk = []; pos = -1
for i in xrange(N):
    st = re.sub('[(), ]',' ',raw_input().strip())
    if st.startswith('tr'):
        stk.append(i)
    elif st.startswith('th') and pos < 0:
        pos = i
        name = st.split()[1]
    elif st.startswith('c'):
        p = stk.pop()
        if p > pos: continue
        if st.split()[1] == name:
            print re.findall('"(.*)"',st)[0]
            sys.exit()
print 'Unhandled Exception'