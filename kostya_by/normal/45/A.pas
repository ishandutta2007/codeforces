program proga;
var
 m:array[1..12] of string;
 st:string;
 i,j,k:longint;
begin
     readln(st);
     readln(k);
     m[1]:='January';
     m[2]:='February';
     m[3]:='March';
     m[4]:='April';
     m[5]:='May';
     m[6]:='June';
     m[7]:='July';
     m[8]:='August';
     m[9]:='September';
     m[10]:='October';
     m[11]:='November';
     m[12]:='December';
     for i:=1 to 12 do begin
         if m[i]=st then begin
            j:=i;
            break;
         end;
     end;
     k:=k+j;
     k:=k mod 12;
     if k=0 then k:=12;
     writeln(m[k]);
end.