var n,i,j,at:longint;
a:array[1..2000] of longint;
s:string;
x,y,z:char;
begin
readln(n);
for i:=1 to n do read(a[i]);
SetLength(s,n);
FillChar(s[1],n,'?');
at:=1;
x:='a'; y:='b';
for i:=n downto 1 do begin
    while a[i]>0 do begin
        for j:=1 to i do begin
            s[at]:=x;
            at:=at+1;
        end;
        z:=x; x:=y; y:=z;
        for j:=1 to i do begin
            a[i-j+1]:=a[i-j+1]-j;
        end;
    end;
end;
Writeln (s);
end.