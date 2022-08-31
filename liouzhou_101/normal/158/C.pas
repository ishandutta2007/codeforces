var
    T,num,now,len,tmp,i : longint;
    pre : array[1..10000] of longint;
    son : array[1..10000,0..100] of longint;
    s,sub : string;
    word : array[1..10000] of string;
    path : array[1..10000] of longint;

begin
    readln(T);
    num:=1;
    now:=1;
    while (T>0) do begin
        T:=T-1;
        readln(s);
        if (s[1]='p') then begin
            len:=0;
            tmp:=now;
            while (true) do begin
                len:=len+1;
                path[len]:=tmp;
                if (tmp=1) then break;
                tmp:=pre[tmp];
            end;
            for i:=len downto 1 do
                write(word[path[i]],'/');
            writeln;
        end else begin
            tmp:=pos(' ',s);
            delete(s,1,tmp);
            if (s[1]='/') then begin
                now:=1;
                delete(s,1,1);
            end;
            s:=s+'/';
            while s<>'' do begin
                tmp:=pos('/',s);
                sub:=copy(s,1,tmp-1);
                delete(s,1,tmp);
                if (sub='..') then
                    now:=pre[now]
                else begin
                    for i:=1 to son[now,0] do
                        if (word[son[now,i]]=sub) then break;
                    if (word[i]=sub) then
                        now:=son[now,i]
                    else begin
                        num:=num+1;
                        son[now,0]:=son[now,0]+1;
                        son[now,son[now,0]]:=num;
                        word[num]:=sub;
                        pre[num]:=now;
                        now:=num;
                    end;
                end;
            end;
        end;
    end;
end.