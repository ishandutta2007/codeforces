program project1;

var
   f : array[1..100] of longint;
   st : string;
   i,j,k,n,m : longint;
begin
     read(st);
     m:=0;
     n:=length(st);
     for i:=1 to n do
     if st[i] = upcase(st[i]) then begin
         inc(m);
         f[i]:=1;
     end else f[i]:=0;
     //writeln(m);
     if (m = n) or ((m = n - 1) and (f[1] = 0)) then begin
        for i:=1 to n do begin
            if st[i] = upcase(st[i]) then begin
               st[i]:=chr(ord(st[i]) + 32);
            end else begin
                st[i]:=upcase(st[i]);
            end;
        end;
     end;
     writeln(st);
end.