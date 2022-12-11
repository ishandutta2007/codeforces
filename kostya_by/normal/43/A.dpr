program adfhdfh;

{$APPTYPE CONSOLE}

var
  i,j,k,n:longint;
  st : array[1..2] of string;
  ch: string;
  s : array[1..2] of longint;
begin
     readln(n);
     s[1]:=0;
     s[2]:=0;
     j:=0;
     for i:=1 to n do begin
         readln(ch);
         if j=2  then begin
            for k:=1 to 2 do begin
                if st[k]=ch then inc(s[k]);
            end;
         end;
         if (j=1) and (st[1]<>ch) then begin
            st[2]:=ch;
            inc(s[2]);
            inc(j);
         end;
         if (j=1) and (st[1]=ch) then begin
            inc(s[1]);
         end;
         if j=0 then begin
            st[1]:=ch;
            inc(s[1]);
            inc(j);
         end;
     end;
     if s[1]>s[2] then writeln(st[1]) else writeln(st[2]);
end.