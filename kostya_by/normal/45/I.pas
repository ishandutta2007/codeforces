program progi;
var
mas:array[1..100] of integer;
i,j,m,a,n,max:longint;
fl:boolean;
begin
  fl:=false;
    readln(n);
    for i:=1 to n do read(mas[i]);
    for i:=1 to n do begin
        for j:=1 to n do begin
            if mas[i]<mas[j] then begin
                a:=mas[i];
                mas[i]:=mas[j];
                mas[j]:=a;
            end;
        end;
    end;
    m:=0;
    max:=-200;
    for i:=1 to n do begin
        if mas[i]<0 then inc(m);
        if mas[i]>0 then begin write(mas[i],' '); fl:=true end;
        if mas[i]>max then max:=mas[i];
    end;
    m:=m-(m mod 2);
    for i:=1 to m do begin write(mas[i],' '); fl:=true end;
    if fl=false then write(max);
end.