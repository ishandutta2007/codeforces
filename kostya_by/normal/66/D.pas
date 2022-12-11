program project1;

var
   bool : array[2..10000] of boolean;
   ans : array[1..50] of longint;
   num : array[1..100] of int64;
   i,j,n,m,dl : longint;
   a : int64;

procedure umn(a : longint);
var
   temp : int64;
   i : longint;
begin
     temp:=0;
     for i:=1 to dl do begin
         temp:=temp + (num[i] * a);
         num[i]:=temp mod 10;
         temp:=temp div 10;
     end;
     while temp > 0 do begin
           inc(dl);
           num[dl]:=temp mod 10;
           temp:=temp div 10;
     end;
end;

begin
     ans[1]:=6;
     ans[2]:=15;
     ans[3]:=10;
     ans[4]:=30;
     for i:=2 to 100 do begin
         if not bool[i] then begin
            j:=i * i;
            while j <= 10000 do begin
                  bool[j]:=true;
                  j:=j + i;
            end;
         end;
     end;
     dl:=1;
     num[1]:=6;
     m:=5;
     read(n);
     if n = 2 then begin
        writeln('-1') ;
        halt;
     end;
     a:=30;
     for i:=1 to n do begin
         if i <= 4 then begin writeln(ans[i]); continue; end;
         //while bool[m] do inc(m);
         //umn(m);
         //for j:=dl downto 1 do write(num[j]);
         //writeln;
         //m:=2;
         a:=a * 2;
         writeln(a);
     end;
end.