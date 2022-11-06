var f1:text;s:ansistring;i,j,e,m:longint;x:string;
begin
        assign(f1,'');reset(f1);
        readln(f1,s);
        for i:=1 to length(s) do
        begin
                if s[i]='0' then begin writeln('YES');write(0);halt;end;
                if s[i]='8' then begin writeln('YES');write(8);halt;end;
        end;
        for i:=1 to length(s)-1 do
        for j:=i+1 to length(s) do
        begin
                x:=s[i]+s[j];
                val(x,m);
                if (s[i]<>'0')and(m mod 8=0) then begin writeln('YES');write(m);halt;end;
        end;
        for i:=1 to length(s)-2 do
        for j:=i+1 to length(s)-1 do
        for e:=j+1 to length(s) do
        begin
                x:=s[i]+s[j]+s[e];
                val(x,m);
                if (s[i]<>'0')and(m mod 8=0) then begin writeln('YES');write(m);halt;end;
        end;
        write('NO');
end.